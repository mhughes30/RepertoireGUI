
#include "RepertoireGUI.h"
#include "ui_RepertoireGUI.h"
#include <ctime>
#include <qmessagebox.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qdebug.h>

#include "RepertoireManager.h"


//--------------- PopulateComboBox ----------------//
template<typename key>
void RepertoireGUI::PopulateComboBox( QComboBox* cb, const std::map<key, std::string>& cbStr )
{
	auto iter = cbStr.cbegin();
	auto end  = cbStr.cend();
	--end;	// go to 1 before the end, since the last element contains the title to use
 	for (; iter != end; ++iter)
	{
		cb->addItem(iter->second.c_str());
	}
}

//--------------- IncrementTableRowCount ----------------//
void RepertoireGUI::AdjustTableRowCount(bool doIncrement)
{
	if (true == doIncrement)
	{
		ui.songTableWidget->setRowCount(++m_numTableRows);
	}
	else
	{
		ui.songTableWidget->setRowCount(--m_numTableRows);
	}

	SetSongSize(m_numTableRows);
}

//--------------- BuildSongTableColumns ----------------//
void RepertoireGUI::BuildSongTableColumns(void)
{
	//--- create labels	
	m_songColumns.append("Composer");	
	m_songColumns.append("Title");
	m_songColumns.append("Instrument");
	m_songColumns.append("Duration");
	m_songColumns.append("Year");
	m_songColumns.append("Type");
	m_songColumns.append("Genre");
	m_songColumns.append("Capo");
	m_songColumns.append("Tuning");
	m_songColumns.append("idx");

	m_numTableColumns = m_songColumns.size();

	ui.songTableWidget->setColumnCount(m_numTableColumns);
	ui.songTableWidget->setHorizontalHeaderLabels(m_songColumns);

	// hide the index column
	bool hideIndexColumn = true;
	ui.songTableWidget->setColumnHidden(m_numTableColumns - 1, hideIndexColumn);
		
	ui.songTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.songTableWidget->horizontalHeader()->show();
	ui.songTableWidget->verticalHeader()->hide();
	ui.songTableWidget->setShowGrid(true);

	ui.songTableWidget->setRowCount(INIT_ROW_SIZE);

	// set fonts
	QFont font;
	font.setPointSize(10);
	font.setBold(true);
	font.setUnderline(true);	
	ui.songTableWidget->horizontalHeader()->setFont(font);
}

//--------------- SetLabelFont ----------------//
void RepertoireGUI::SetLabelFont(QLabel* label, uint8_t fontSize, bool isBold, bool isUnderline)
{
	QFont font = label->font();
	font.setPointSize(fontSize);
	font.setBold(isBold);
	font.setUnderline(isUnderline);

	label->setFont(font);
	label->setAlignment(Qt::AlignCenter);
}

//--------------- SetSongSize ----------------//
void RepertoireGUI::SetSongSize(size_t numSongs)
{
	const QString prefix = "Repertoire Size: ";

	QString sizeStr = prefix + QString::number(numSongs);
	ui.labelSongSize->setText(sizeStr);
}

//--------------- ConfigYearBox ----------------//
void RepertoireGUI::ConfigYearBox(void)
{
	const int TIME_BASIS_YEAR = 1900;	// ctime starts from 1900
	int minYear = 1000;					// hardcode to 1000 AD

	// Grab the current year for the maxYear
	time_t curTime = time(NULL);
	struct tm* tmTime = localtime(&curTime);
	int maxYear = tmTime->tm_year + TIME_BASIS_YEAR;

	ui.spinBoxYear->setRange(minYear, maxYear);
	ui.spinBoxYear->setSingleStep(1);
	ui.spinBoxYear->setValue(maxYear);
}


//--------------- RepertoireGUI ----------------//
RepertoireGUI::RepertoireGUI( QWidget *parent )
	: QWidget(parent)
{
	ui.setupUi(this);

	//--- populate all of the combox boxes
	PopulateComboBox(ui.boxInstrument,		EnumToStr::getStrFromInstrument);
	PopulateComboBox(ui.boxGenre,			EnumToStr::getStrFromGenre);	
	PopulateComboBox(ui.boxInstrumentation, EnumToStr::getStrFromInstrumentation);
	PopulateComboBox(ui.boxGuitarCapo,		EnumToStr::getStrFromCapo);
	PopulateComboBox(ui.boxGuitarTuning,	EnumToStr::getStrFromTuning);
	
	//--- configure the song table
	BuildSongTableColumns();

	//--- Set all label font-related properties
	SetLabelFont(ui.labelSongTable,		  18, true, false);
	SetLabelFont(ui.labelSongSize,		  10, true, false);
	SetLabelFont(ui.labelGenre,			  10, true, false);
	SetLabelFont(ui.labelGuitarCapo,	  10, true, false);
	SetLabelFont(ui.labelGuitarTune,	  10, true, false);
	SetLabelFont(ui.labelInstrument,	  10, true, false);
	SetLabelFont(ui.labelInstrumentation, 10, true, false);
	SetLabelFont(ui.labelCompoition,	  10, true, false);
	SetLabelFont(ui.labelComposer,		  10, true, false);
	SetLabelFont(ui.labelYear,			  10, true, false);
	SetLabelFont(ui.labelDuration,		  10, true, false);

	//--- ConfigYearBox
	ConfigYearBox();

	//--- read in repertoire if it exists
	CheckRepertoire();
}

//--------------- CheckRepertoire ----------------//
//- Reads the repertoire at startup and populates the table with any songs
void RepertoireGUI::CheckRepertoire()
{
	static std::vector<QString> rowVec(m_numTableColumns);
	RepertoireManager* repMgr = RepertoireManager::GetInstance();
	repMgr->ReadRepertoireFromDisk();
	auto songItr = repMgr->cbegin();
	auto songEnd = repMgr->cend();

	SetSongSize(repMgr->GetRepertoireSize());

	for (; songItr != songEnd; ++songItr)
	{
		ISong* song = songItr->get();
		Guitar* curSong = static_cast<Guitar*>(song);
		// composer
		Human hum;
		curSong->GetComposer(hum);
		rowVec[0] = hum.GetName(Human::NAME::FULL).c_str();
		// Title
		rowVec[1] = curSong->GetTitle().c_str();
		// Instrument
		rowVec[2] = EnumToStr::getStrFromInstrument.at(curSong->GetInstrument()).c_str();
		// Duration
		Duration dur;
		curSong->GetDuration(dur);
		rowVec[3] = dur.GetMinSecStr().c_str();
		// year
		rowVec[4] = QString::number( curSong->GetYear() );
		// Instrumentation Type
		rowVec[5] = EnumToStr::getStrFromInstrumentation.at(curSong->GetInstrumentation()).c_str();
		// genre
		rowVec[6] = EnumToStr::getStrFromGenre.at(curSong->GetGenre()).c_str();
		// capo and tuning
		GuitarConfig gc;
		curSong->GetGuitarConfig(gc);
		rowVec[7] = EnumToStr::getStrFromCapo.at(gc.GetCapoFret()).c_str();
		rowVec[8] = EnumToStr::getStrFromTuning.at(gc.GetTuning()).c_str();
		
		WriteDataToRow(rowVec);
	}
}

//--------------- WriteDataToRow ----------------//
void RepertoireGUI::WriteDataToRow(std::vector<QString>& data)
{
	//--- update the song position index
	data[m_numTableColumns-1] = QString::number(m_numTableRows);

	//--- indicate another row has been added
	AdjustTableRowCount(true);

	//--- add row of items to the QT table	
	for (int colIdx = 0; colIdx < m_numTableColumns; ++colIdx)
	{
		QTableWidgetItem* item = new QTableWidgetItem();
		item->setText(data[colIdx]);
		// make the data not editable
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui.songTableWidget->setItem(m_numTableRows-1, colIdx, item);		
	}
}

//--------------- on_buttonDelete_clicked ----------------//
void RepertoireGUI::on_buttonDelete_clicked()
{
	// don't remove a row that doesn't exist. 
	if (ui.songTableWidget->rowCount() == INIT_ROW_SIZE)
	{
		return;
	}

	//-- row to be removed
	int rowRemoved = ui.songTableWidget->currentRow();

	//-- add to the list of songs to be removed
	QTableWidgetItem* item = ui.songTableWidget->item(rowRemoved, m_numTableColumns - 1);
	int songIdx = item->text().toInt();

	// only add the index of the song to be edited, if it has not already been added
	auto it = std::find(m_songIndexToDelete.cbegin(), m_songIndexToDelete.cend(), songIdx);
	if (it != m_songIndexToDelete.cend())
	{
		return;
	}
	m_songIndexToDelete.push_back(songIdx);

	//-- remove from the table
	ui.songTableWidget->removeRow(rowRemoved);
	AdjustTableRowCount(false);
}

//--------------- on_buttonSave_clicked ----------------//
void RepertoireGUI::on_buttonSave_clicked()
{
	//-- alert user if saving an empty list
	if (ui.songTableWidget->rowCount() == INIT_ROW_SIZE)
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Warning: Save List");
		msgBox.setText("List is empty: Are you sure you want to save?");
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.addButton(QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		if (msgBox.exec() == QMessageBox::No)
		{
			return;
		}
	}

	RepertoireManager* repMgr = RepertoireManager::GetInstance();

	//--- loop through elements to delete	
	for (auto iter = m_songIndexToDelete.cbegin(); iter != m_songIndexToDelete.cend(); ++iter)
	{
		uint16_t idx = static_cast<uint16_t>(*iter);
		repMgr->EraseSong(idx);
	}

	//-- write the data		
	repMgr->WriteRepertoireToDisk();	
}

//--------------- on_addsongButton_clicked ----------------//
void RepertoireGUI::on_buttonAdd_clicked()
{
	static std::vector<QString> dispVec(m_numTableColumns);

	//--- Get the composer and composition
	QString composer	= ui.textEditComposer->toPlainText();
	QString composition = ui.textEditComposition->toPlainText();	
	if (composer.isEmpty() || composition.isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("ERROR: Add Song");
		msgBox.setText("Composer/Composition cannot be emtpy.");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
	}

	//--- Get current values of all combo-box items
	std::tuple<int, QString> instrumentT( ui.boxInstrument->currentIndex(), ui.boxInstrument->currentText() );
	std::tuple<int, QString> instTypeT( ui.boxInstrumentation->currentIndex(), ui.boxInstrumentation->currentText() );
	std::tuple<int, QString> genreT( ui.boxGenre->currentIndex(), ui.boxGenre->currentText() );
	std::tuple<int, QString> guitarTuningT( ui.boxGuitarTuning->currentIndex(), ui.boxGuitarTuning->currentText() );
	std::tuple<int, QString> guitarCapoT( ui.boxGuitarCapo->currentIndex(), ui.boxGuitarCapo->currentText() );

	//--- Get the spinbox year
	uint16_t year = static_cast<uint16_t>( ui.spinBoxYear->value() );

	//--- Get the Duration
	QTime time = ui.timeEditDuration->time();
	uint16_t duration = static_cast<uint16_t>( 60*time.minute() + time.second() );

	//--- Populate the Row in the Table
	dispVec[0] = composer;
	dispVec[1] = composition;
	dispVec[2] = std::get<1>(instrumentT);
	dispVec[3] = time.toString();
	dispVec[4] = QString::number(year); 
	dispVec[5] = std::get<1>(instTypeT);
	dispVec[6] = std::get<1>(genreT);
	dispVec[7] = std::get<1>(guitarCapoT);
	dispVec[8] = std::get<1>(guitarTuningT);

	WriteDataToRow(dispVec);

	//-- add data to archive
	RepertoireManager* repMgr = RepertoireManager::GetInstance();
	Guitar gc;
	// composer
	Human hum;
	hum.SetName(Human::NAME::FULL, composer.toStdString());
	gc.SetComposer(std::make_unique<Human>(hum));
	// duration
	Duration dur(duration);
	gc.SetDuration(std::make_unique<Duration>(dur));
	// genre
	gc.SetGenre( static_cast<GENRE>(std::get<0>(genreT)) );
	// guitar config
	GuitarConfig gcConf;
	gcConf.SetCapoFret( static_cast<GuitarConfig::CAPO>(std::get<0>(guitarCapoT)) );
	gcConf.SetTuning( static_cast<GuitarConfig::TUNING>(std::get<0>(guitarTuningT)) );
	gc.SetGuitarConfig(gcConf);
	// instrument
	gc.SetInstrument( static_cast<INSTRUMENT>(std::get<0>(instrumentT)) );
	// instrumentation
	gc.SetInstrumentation( static_cast<INSTRUMENTATION>(std::get<0>(instTypeT)) );
	// title
	gc.SetTitle(composition.toStdString());
	// year
	gc.SetYear(year);
	repMgr->AppendSong(gc);
}

//--------------- on_buttonSaveToFile_clicked ----------------//
void RepertoireGUI::on_buttonSaveToFile_clicked()
{
	SaveFormattedRepertoireToFile();
}

//--------------- SaveFormattedRepertoireToFile ----------------//
void RepertoireGUI::SaveFormattedRepertoireToFile(void)
{
	// TODO - finish
	QFile file("Repertoire.txt");
	if ( !file.open(QFile::WriteOnly | QFile::Text) )
	{
		qDebug() << " Could not open file.";
		return;
	}

	QTextStream ots(&file);
	QStringList strList;
	const QTableWidget* table = ui.songTableWidget;

	for (int col = 0; col < table->columnCount() - 1; ++col)
	{
		strList << "\" " + table->horizontalHeaderItem(col)->data(Qt::DisplayRole).toString() + "\" ";
	}
	ots << strList.join(";");
	file.close();
}


#pragma once

#include <QtWidgets/QWidget>
#include "ui_RepertoireGUI.h"

#include "RepertoireManager.h"

class RepertoireGUI : public QWidget
{
	Q_OBJECT

public:
	RepertoireGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::RepertoireGUIClass ui;

	const uint8_t INIT_ROW_SIZE = 0;

	size_t m_numTableColumns = 0;				// number of columns in the table
	size_t m_numTableRows    = INIT_ROW_SIZE;	// number of rows in the table
	size_t m_theEndColumn;
	
	// columns used to populate the table widget
	std::map<SONG_CAT, int> m_headingIdx
	{  
		{ SONG_CAT::COMPOSER,	 0 },
		{ SONG_CAT::TITLE,		 1 },
		{ SONG_CAT::INSTRUMENT,  2 },
		{ SONG_CAT::DURATION,	 3 },
		{ SONG_CAT::YEAR,		 4 },
		{ SONG_CAT::INSTR_TYPE,  5 },
		{ SONG_CAT::GENRE,		 6 },
		{ SONG_CAT::GUITAR_CAPO, 7 },
		{ SONG_CAT::GUITAR_TUNE, 8 },
		{ SONG_CAT::MAX,		 9 }		
	};

	// tracks songs to be deleted upon SAVE
	std::vector<int> m_songIndexToDelete;

	//-- populates all the combo boxes for selecting a song
	template<typename key>
	void PopulateComboBox(QComboBox* cb, const std::map<key, std::string>& cbStr);
	//-- builds the column names in the table view 
	void BuildSongTableColumns(void);
	//-- formats fonts for all labels
	void SetLabelFont(QLabel* label, uint8_t fontSize, bool isBold, bool isUnderline);
	//-- sets the repertoire size field
	void SetSongSize(size_t numSongs);
	//-- sets up the year-box
	void ConfigYearBox(void);
	//-- increments/decrements the # of rows in the table
	void AdjustTableRowCount(bool doIncrement);	
	//-- reads the archived table, and loads it into the table view
	void CheckRepertoire();
	//-- writes 1 row of data to the tavle view
	void WriteDataToRow(std::map<SONG_CAT, std::string>& songData);
	//-- saves the repertoire to a human-readable file
	void SaveFormattedRepertoireToFile(void);

private slots:
	void on_buttonAdd_clicked();
	void on_buttonSave_clicked();
	void on_buttonDelete_clicked();
	void on_buttonSaveToFile_clicked();
};

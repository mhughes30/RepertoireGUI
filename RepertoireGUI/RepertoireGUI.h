#pragma once

#include <QtWidgets/QWidget>
#include "ui_RepertoireGUI.h"

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
	
	// columns used to populate the table widget
	QStringList m_songColumns;

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
	void WriteDataToRow(std::vector<QString>& data);
	//-- saves the repertoire to a human-readable file
	void SaveFormattedRepertoireToFile(void);

private slots:
	void on_buttonAdd_clicked();
	void on_buttonSave_clicked();
	void on_buttonDelete_clicked();
	void on_buttonSaveToFile_clicked();
};

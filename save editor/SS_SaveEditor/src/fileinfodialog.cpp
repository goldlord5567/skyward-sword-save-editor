#include "fileinfodialog.h"
#include "ui_fileinfodialog.h"

#include "gamefile.h"

#include <QRadioButton>

FileInfoDialog::FileInfoDialog(QWidget *parent, GameFile& game) :
    QDialog(parent),
    m_ui(new Ui::FileInfoDialog)
{
    m_ui->setupUi(this);
    m_gameFile = &game;

    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(m_ui->ntscURadioBtn);
    group->addButton(m_ui->ntscJRadioBtn);
    group->addButton(m_ui->palRadioBtn);

    if (m_gameFile != NULL)
    {
        m_ui->noFileInfoLbl->hide();
        switch(m_gameFile->GetRegion())
        {
        case GameFile::NTSCU:
            m_ui->ntscURadioBtn->setChecked(true);
            break;
        case GameFile::NTSCJ:
            m_ui->ntscJRadioBtn->setChecked(true);
            break;
        case GameFile::PAL:
            m_ui->palRadioBtn->setChecked(true);
            break;
        }

        int count = 0;

        GameFile::Game oldGame = m_gameFile->GetGame();
        for (int i = 0; i < 3; i++)
        {
            m_gameFile->SetGame((GameFile::Game)i);
            if (!m_gameFile->IsNew())
                count++;
        }
        m_gameFile->SetGame(oldGame);

        m_ui->checkSumLbl->setText(tr("Adventure Checksum: 0x").append(QString("").sprintf("%08X", m_gameFile->GetChecksum())));
        m_ui->adventureCountLbl->setText(tr("Adventure Count: %1").arg(count));
        m_ui->currentAdventureLbl->setText(tr("Current Adventure: %1 - %2").arg(m_gameFile->GetGame() + 1).arg(m_gameFile->GetPlayerName()));
    }
    else
    {
        m_ui->fileInfoGrpBox->hide();
    }


    connect(group, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onRegionChanged(QAbstractButton*)));
}

FileInfoDialog::~FileInfoDialog()
{
    delete m_ui;
}


void FileInfoDialog::onRegionChanged(QAbstractButton *)
{
    if (m_gameFile == NULL);
        return;

    if (m_ui->ntscURadioBtn->isChecked())
        m_gameFile->SetRegion(GameFile::NTSCU);
    else if (m_ui->ntscJRadioBtn->isChecked())
        m_gameFile->SetRegion(GameFile::NTSCJ);
    else if (m_ui->palRadioBtn->isChecked())
        m_gameFile->SetRegion(GameFile::PAL);
}
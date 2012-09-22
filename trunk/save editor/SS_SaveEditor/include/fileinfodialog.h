// This file is part of WiiKing2 Editor.
//
// WiiKing2 Editor is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Wiiking2 Editor is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with WiiKing2 Editor.  If not, see <http://www.gnu.org/licenses/>

#ifndef FILEINFODIALOG_H
#define FILEINFODIALOG_H

#include <QDialog>
class SkywardSwordFile;
class QAbstractButton;

namespace Ui {
    class FileInfoDialog;
}

class FileInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileInfoDialog(QWidget *parent, SkywardSwordFile& game);
    ~FileInfoDialog();

private slots:
    void onRegionChanged(QAbstractButton*);
    void onAccepted();
private:
    enum StringType {Title, Subtitle};
    QString GetRegionString(int region, StringType type) const;
    Ui::FileInfoDialog *m_ui;
    SkywardSwordFile* m_gameFile;
    int               m_region;
};

#endif // FILEINFODIALOG_H
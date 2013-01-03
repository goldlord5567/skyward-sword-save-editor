#include "gameinfowidget.h"
#include "ui_gameinfowidget.h"

GameInfoWidget::GameInfoWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::GameInfoWidget)
{
    m_ui->setupUi(this);
}

GameInfoWidget::~GameInfoWidget()
{
    delete m_ui;
}

QString GameInfoWidget::playerName() const
{
    return m_ui->playerNameLineEdit->text();
}

quint32 GameInfoWidget::rupees() const
{
    return m_ui->rupeesSpinBox->value();
}

quint32 GameInfoWidget::heartContainers() const
{
    return m_ui->heartContainersSpinBox->value();
}

quint32 GameInfoWidget::currentHealth() const
{
    return m_ui->currentHealthSpinBox->value();
}

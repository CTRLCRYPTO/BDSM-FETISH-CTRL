// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2012-2015 The PPCoin developers
// Copyright (c) 2013-2017 The Novacoin developers
// Copyright (c) 2014-2015 The BDSM COIN(BDSM) & Fetish Coin(FETISH) developers
// Copyright (c) 2014-2017 The BDSM-FETISH(WHIPPED) developers
// Copyright (c) 2018 The BDSM-FETISH(CTRL) developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
    class AboutDialog;
}
class ClientModel;

/** "About" dialog box */
class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

    void setModel(ClientModel *model);
private:
    Ui::AboutDialog *ui;

private slots:
    void on_buttonBox_accepted();
};

#endif // ABOUTDIALOG_H

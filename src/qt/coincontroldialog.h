// Copyright (c) 2011-2015 The Bitcoin Core developers
// Copyright (c) 2018-2022 Thought Network Ltd
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef THOUGHT_QT_COINCONTROLDIALOG_H
#define THOUGHT_QT_COINCONTROLDIALOG_H

#include <amount.h>

#include <QAbstractButton>
#include <QAction>
#include <QDialog>
#include <QList>
#include <QMenu>
#include <QPoint>
#include <QString>
#include <QTreeWidgetItem>

class WalletModel;

class CCoinControl;

namespace Ui {
    class CoinControlDialog;
}

#define ASYMP_UTF8 "\xE2\x89\x88"

class CCoinControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CCoinControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CCoinControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CCoinControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};


class CoinControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlDialog(CCoinControl& coin_control, WalletModel* model, QWidget *parent = nullptr);
    ~CoinControlDialog();

    // static because also called from sendcoinsdialog
    static void updateLabels(CCoinControl& m_coin_control, WalletModel*, QDialog*);

    static QList<CAmount> payAmounts;
    static bool fSubtractFeeFromAmount;

private:
    Ui::CoinControlDialog *ui;
    CCoinControl& m_coin_control;
    WalletModel *model;
    int sortColumn;
    Qt::SortOrder sortOrder;

    QMenu *contextMenu;
    QTreeWidgetItem *contextMenuItem;
    QAction *copyTransactionHashAction;
    QAction *lockAction;
    QAction *unlockAction;

    bool fHideAdditional{true};

    void sortView(int, Qt::SortOrder);
    void updateView();

    enum
    {
        COLUMN_CHECKBOX = 0,
        COLUMN_AMOUNT,
        COLUMN_LABEL,
        COLUMN_ADDRESS,
        COLUMN_COINJOIN_ROUNDS,
        COLUMN_DATE,
        COLUMN_CONFIRMATIONS,
    };

    enum
    {
        TxHashRole = Qt::UserRole,
        VOutRole
    };

    friend class CCoinControlWidgetItem;

private Q_SLOTS:
    void showMenu(const QPoint &);
    void copyAmount();
    void copyLabel();
    void copyAddress();
    void copyTransactionHash();
    void lockCoin();
    void unlockCoin();
    void clipboardQuantity();
    void clipboardAmount();
    void clipboardFee();
    void clipboardAfterFee();
    void clipboardBytes();
    void clipboardLowOutput();
    void clipboardChange();
    void radioTreeMode(bool);
    void radioListMode(bool);
    void viewItemChanged(QTreeWidgetItem*, int);
    void headerSectionClicked(int);
    void buttonBoxClicked(QAbstractButton*);
    void buttonSelectAllClicked();
    void buttonToggleLockClicked();
    void updateLabelLocked();
    void on_hideButton_clicked();
};

#endif // THOUGHT_QT_COINCONTROLDIALOG_H

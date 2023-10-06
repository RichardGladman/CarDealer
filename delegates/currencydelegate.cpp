#include "currencydelegate.h"

#include <QPainter>

CurrencyDelegate::CurrencyDelegate(QObject *parent) : QStyledItemDelegate{parent}
{

}


void CurrencyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() != column) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    double amount = index.data().toDouble();

    painter->drawText(option.rect, Qt::AlignVCenter, QString::number(amount, 'f', 2));
}

int CurrencyDelegate::getColumn() const
{
    return column;
}

void CurrencyDelegate::setColumn(int newColumn)
{
    column = newColumn;
}

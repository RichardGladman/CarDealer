#include "currencydelegate.h"

#include <QPainter>
#include "../settings/settings.h"

CurrencyDelegate::CurrencyDelegate(QObject *parent) : QStyledItemDelegate{parent}
{

}


void CurrencyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    extern Settings *settings;

    if (index.column() != column) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    double amount = index.data().toDouble();
    QString text = settings->getCurrency() + QString::number(amount, 'f', 2);

    painter->drawText(option.rect, Qt::AlignVCenter, text);
}

int CurrencyDelegate::getColumn() const
{
    return column;
}

void CurrencyDelegate::setColumn(int newColumn)
{
    column = newColumn;
}

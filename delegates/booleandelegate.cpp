#include "booleandelegate.h"

#include <QPainter>

BooleanDelegate::BooleanDelegate(int column, QObject *parent) : QStyledItemDelegate{parent},  column{column}
{

}


void BooleanDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() != column) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    bool auctioned = index.data().toBool();
    if(auctioned) {
        painter->drawText(option.rect, Qt::AlignVCenter | Qt::AlignHCenter, "✔️");
    }
}

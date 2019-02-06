/*
    RPG Paper Maker Copyright (C) 2017-2019 Marie Laporte

    This file is part of RPG Paper Maker.

    RPG Paper Maker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPG Paper Maker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WIDGETTABLEPROGRESSION_H
#define WIDGETTABLEPROGRESSION_H

#include <QTableWidget>
#include <QtCharts>
#include "systemprogressiontable.h"

class WidgetTableProgression : public QTableWidget
{
    Q_OBJECT
public:
    static const QString NAME_LEVEL;

    explicit WidgetTableProgression(QWidget *parent = nullptr);
    ~WidgetTableProgression();
    void setEditable(bool b);
    QHash<int, int> * table();
    void setTable(QHash<int, int> *table);
    WidgetTableProgression * totalWidget() const;
    void setTotalWidget(WidgetTableProgression *w);

    void initialize(int rows, QString progression);
    void updateWithBaseInflation(int base, double inflation, int maxLevel,
        QHash<int, int> *subTable = nullptr);
    void updateWithEasing(SystemProgressionTable* progression, QChartView *chart,
        int finalLevel);
    int easingLinear(int x, int start, int change, int duration);
    int easingQuadraticIn(int x, int start, int change, int duration);
    int easingQuadraticOut(int x, int start, int change, int duration);
    int easingCubicIn(int x, int start, int change, int duration);
    int easingCubicOut(int x, int start, int change, int duration);
    int easingQuarticIn(int x, int start, int change, int duration);
    int easingQuarticOut(int x, int start, int change, int duration);
    int easingQuinticIn(int x, int start, int change, int duration);
    int easingQuinticOut(int x, int start, int change, int duration);
    void updateTotal();

protected:
    bool m_completing;
    QHash<int, int> *m_table;
    WidgetTableProgression *m_totalWidget;

public slots:
    void on_cellChanged(int row, int column);
};

#endif // WIDGETTABLEPROGRESSION_H

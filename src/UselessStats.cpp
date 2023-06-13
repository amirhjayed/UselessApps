/*
* Copyleft (l) Useless NV. All rights dispensed.
* Free and for useless use only. The contents of this document consituts shared
* information of Useless Group of companies. If you use this in a useful way, you dissapoint me.
* Author: hajayedamir@gmail.com
*/

#include "UselessStats.h"

#include "GlobalConstants.h"

#include <QDir>
#include <QFile>
#include <QStandardPaths>

#include <QJsonObject>
#include <QJsonDocument>

//---------------------------------------------------------------------
UselessStats::UselessStats(const QString& stats_filepath, QObject* parent)
    : QObject(parent)
{
    QFile useless_stats_file(stats_filepath);

    useless_stats_file.open(QIODevice::ReadOnly);
    QByteArray bytes = useless_stats_file.readAll();
    auto document = QJsonDocument::fromJson(bytes);
    auto root_object = document.object();
    m_opened_count = root_object.value(constants::OPEN_COUNTER_STAT).toInt(1);
    useless_stats_file.close();

    useless_stats_file.open(QIODevice::WriteOnly);
    root_object.insert(constants::OPEN_COUNTER_STAT, ++m_opened_count);
    document.setObject(root_object);
    useless_stats_file.write(document.toJson());
    useless_stats_file.close();
}

//---------------------------------------------------------------------
int UselessStats::getOpenedCount() const
{
    return m_opened_count;
}

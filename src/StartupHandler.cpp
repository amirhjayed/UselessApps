/*
* Copyleft (l) Useless NV. All rights dispensed.
* Free and for useless use only. The contents of this document consitutes shared
* information of Useless Group of companies. If you use this in a useful way, you dissapoint me.
* Author: hajayedamir@gmail.com
*/

#include "StartupHandler.h"
#include "GlobalConstants.h"

#include <QDir>
#include <QFile>
#include <QStandardPaths>

#include <QJsonObject>
#include <QJsonDocument>

#include <QDebug>

//---------------------------------------------------------------------
bool StartupHandler::setupApplication()
{
    QDir appdata_dir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (!appdata_dir.exists())
    {
        appdata_dir.mkdir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    }

    m_useless_stats_path = appdata_dir.absoluteFilePath(constants::STATS_FILENAME) + ".json";
    QFile useless_stats_file(m_useless_stats_path);
    if (!useless_stats_file.exists())
    {
        QJsonObject content
        {
            {constants::OPEN_COUNTER_STAT, 0}
        };

        QJsonDocument document;
        document.setObject(content);

        QByteArray bytes = document.toJson(QJsonDocument::Indented);
        if( useless_stats_file.open(QIODevice::WriteOnly))
        {
            QTextStream stream( &useless_stats_file );
            stream << bytes;
            useless_stats_file.close();
        }
        else
        {
            qWarning() << "Failed to open stats file.";
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------
QString StartupHandler::getUselessStatsPath() const
{
    return m_useless_stats_path;
}

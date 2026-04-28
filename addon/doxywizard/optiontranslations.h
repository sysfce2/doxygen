/******************************************************************************
 *
 * Copyright (C) 1997-2026 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby
 * granted. No representations are made about the suitability of this software
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 */

#ifndef OPTIONTRANSLATIONS_H
#define OPTIONTRANSLATIONS_H

#include <QString>
#include <QMap>
#include <QObject>

class OptionTranslations : public QObject
{
    Q_OBJECT

public:
    static OptionTranslations& instance();
    QString translate(const QString &optionName);
    static QString trStatic(const QString &optionName);
    void retranslate();

private:
    OptionTranslations() {}
    Q_DISABLE_COPY(OptionTranslations)

    void initTranslations();
    QMap<QString, QString> m_translations;
    bool m_initialized = false;
};

#endif // OPTIONTRANSLATIONS_H

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

#ifndef TRANSLATIONMANAGER_H
#define TRANSLATIONMANAGER_H

#include <QObject>
#include <QTranslator>
#include <QStringList>
#include <QMap>

class TranslationManager : public QObject
{
  Q_OBJECT

  public:
    struct LanguageInfo
    {
      QString code;
      QString nativeName;
      QString englishName;
      QString tsFile;
      QString qmFile;
      QString optionsQmFile;
    };

    TranslationManager();
    ~TranslationManager();
    Q_DISABLE_COPY(TranslationManager)

    void initialize();
    QStringList availableLanguages() const;
    QString currentLanguage() const;
    QString currentLanguageCode() const;
    LanguageInfo languageInfo(const QString &langCode) const;
    bool isLanguageAvailable(const QString &langCode) const;

    QString systemLanguageCode() const;
    QString fallbackLanguageCode() const;

  public slots:
    bool switchLanguage(const QString &langCode);
    void switchToSystemLanguage();
    void switchToFallbackLanguage();

  signals:
    void languageChanged(const QString &langCode);
    void languageSwitchFailed(const QString &langCode, const QString &error);

  private:
    void loadAvailableLanguages();
    QString detectSystemLanguage() const;
    bool loadTranslation(const QString &qmFilePath);
    void unloadTranslation();
    QString qmFilePath(const QString &langCode) const;
    QString qmOptionsFilePath(const QString &langCode) const;
    QString tsFilePath(const QString &langCode) const;

    QTranslator *m_translator;
    QTranslator *m_qtTranslator;
    QTranslator *m_optionsTranslator;
    QString m_currentLangCode;
    QMap<QString, LanguageInfo> m_languages;
    bool m_initialized;
};

#endif // TRANSLATIONMANAGER_H

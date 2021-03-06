// Aseprite
// Copyright (C) 2001-2016  David Capello
//
// This program is distributed under the terms of
// the End-User License Agreement for Aseprite.

#ifndef APP_UI_FILE_SELECTOR_H_INCLUDED
#define APP_UI_FILE_SELECTOR_H_INCLUDED
#pragma once

#include "app/file_selector.h"
#include "base/unique_ptr.h"
#include "ui/window.h"

#include "file_selector.xml.h"

#include <string>

namespace ui {
  class Button;
  class ComboBox;
  class Entry;
}

namespace app {
  class FileList;
  class FileListView;
  class IFileItem;

  class FileSelector : public app::gen::FileSelector {
  public:
    FileSelector(FileSelectorType type, FileSelectorDelegate* delegate);
    ~FileSelector();

    void goBack();
    void goForward();
    void goUp();
    void goInsideFolder();

    // Shows the dialog to select a file in the program.
    std::string show(const std::string& title,
                     const std::string& initialPath,
                     const std::string& showExtensions);

  private:
    void updateLocation();
    void updateNavigationButtons();
    void addInNavigationHistory(IFileItem* folder);
    void onGoBack();
    void onGoForward();
    void onGoUp();
    void onNewFolder();
    void onLocationCloseListBox();
    void onFileTypeChange();
    void onFileListFileSelected();
    void onFileListFileAccepted();
    void onFileListCurrentFolderChanged();
    void onExtraOptions();
    std::string getSelectedExtension() const;
    void updateExtraLabel();

    class ArrowNavigator;
    class CustomFileNameItem;
    class CustomFolderNameItem;
    class CustomFileNameEntry;
    class ExtrasWindow;

    FileSelectorType m_type;
    FileSelectorDelegate* m_delegate;
    std::string m_defExtension;
    CustomFileNameEntry* m_fileName;
    FileList* m_fileList;
    FileListView* m_fileView;
    ExtrasWindow* m_extras;

    // If true the navigation_history isn't
    // modified if the current folder changes
    // (used when the back/forward buttons
    // are pushed)
    bool m_navigationLocked;
  };

} // namespace app

#endif

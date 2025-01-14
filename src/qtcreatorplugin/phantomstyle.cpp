#include "phantomstyleconstants.h"
#include "phantomstyletr.h"

#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>
#include <coreplugin/manhattanstyle.h>

#include <extensionsystem/iplugin.h>

#include <QApplication>

#include <phantom/phantomstyle.h>

namespace Phantom::Internal {

class PhantomStylePlugin final : public ExtensionSystem::IPlugin {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE
                        "PhantomStyle.json")

public:
  PhantomStylePlugin() = default;

  ~PhantomStylePlugin() final {
  }

  void initialize() final {
    auto manhattanStyle = new ManhattanStyle(QApplication::style()->name());
    manhattanStyle->setBaseStyle(new PhantomStyle);

    QApplication::setStyle(manhattanStyle);
  }

  void extensionsInitialized() final {
  }

  ShutdownFlag aboutToShutdown() final {
    return SynchronousShutdown;
  }
};

} // namespace PhantomStyle::Internal

#include <phantomstyle.moc>

#ifndef LAYOUTFACTORY_H
#define LAYOUTFACTORY_H

class QWidget;

namespace LayoutFactory {
enum SPACING { TIGHT };
template <typename LayoutType>
LayoutType* createLayout(QWidget* parent = nullptr) {
  LayoutType* layout = new LayoutType(parent);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(1);
  layout->setAlignment(Qt::AlignTop);
  return layout;
}

}  // namespace LayoutFactory

#endif  // LAYOUTFACTORY_H

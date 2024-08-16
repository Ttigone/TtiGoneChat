#include "data/data_session_label.h"
#include "data/data_talk_init.h"

#include "storage/session_storage.h"


namespace Data {
SessionLabelModel::SessionLabelModel(QObject* parent)
    : QAbstractListModel(parent), all_record_(0) {
  init();
}

SessionLabelModel::~SessionLabelModel() {}

int SessionLabelModel::rowCount(const QModelIndex& parent) const {
  return all_record_;
}

QVariant SessionLabelModel::data(const QModelIndex& index, int role) const {
  // 1. 获取数据个数  2. 获取记录
  if (!index.isValid() || index.row() > all_record_) {
    return QVariant();
  }
  // 自定义的数据
  if (role == tRole)
  {
    return QVariant::fromValue(Storage::tSessionLabelData[index.row()]);
  } else
  {
    return QVariant();
  }
  return QVariant();
}

void SessionLabelModel::updateModel(const QModelIndex& index,
                                    const QDateTime& time) {}

void SessionLabelModel::init() {
  all_record_ = Storage::readStorageSessionLabelLocation();
  for (int i = 0; i < all_record_; ++i) {
    this->insertRow(i, QModelIndex());
    this->setData(this->index(i),
                  QVariant::fromValue(Storage::tSessionLabelData),
                  tRole);
  }
}

}  // namespace Data

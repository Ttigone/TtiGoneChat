#include "data/data_session_label.h"
#include "data/data_talk_init.h"

#include "storage/session_storage.h"


namespace Data {
SessionLabelModel::SessionLabelModel(QObject* parent)
    : QAbstractListModel(parent) {
  init();
}

SessionLabelModel::~SessionLabelModel() {}

int SessionLabelModel::loadData(int page, int page_size)
{
  QVector<StorageSessionLabel> newData = Storage::fetchDataFromDatabase(page, page_size);
  if (newData.size() == 0)
  {
    return 0;
  }
  beginInsertRows(QModelIndex(), data_.size(),
                  data_.size() + newData.size() - 1);
  data_ += newData;
  endInsertRows();
  return newData.size();
}

int SessionLabelModel::rowCount(const QModelIndex& parent) const {
  return data_.size();
}

QVariant SessionLabelModel::data(const QModelIndex& index, int role) const {
  // 1. 获取数据个数  2. 获取记录
  if (!index.isValid() || index.row() > data_.size()) {
    return QVariant();
  }
  // 自定义的数据
  if (role == tRole)
  {
    // 输出了 2 次
    //qDebug() << index.row();
    return QVariant::fromValue(data_[index.row()]);
  } else
  {
    return QVariant();
  }
}

void SessionLabelModel::updateModel(const QModelIndex& index,
                                    const QDateTime& time) {}

void SessionLabelModel::init() {
  // 一次性读取全部数据 ....
  //all_record_ = Storage::readStorageSessionLabelLocation();
  //qDebug() << "all_record_:" << all_record_;
	//qDebug() << Storage::tSessionLabelData.size();
  for (int i = 0; i < data_.size(); ++i) {
    this->insertRow(i, QModelIndex());
    this->setData(this->index(i),
                  QVariant::fromValue(data_.at(i)),
                  tRole);
    //qDebug() << (Storage::tSessionLabelData).at(i).session_label_icon_path;
  }
}

}  // namespace Data

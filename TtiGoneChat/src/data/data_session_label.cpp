#include "data/data_session_label.h"

#include "data_document.h"
#include "data_talk.h"
#include "data/data_talk_init.h"
#include "storage/session_storage.h"

#include "window/window_stack.h"
#include "window/window_media_preview.h"
#include "storage/history_storage.h"

namespace Data {
SessionLabelModel::SessionLabelModel(QObject* parent)
    : QAbstractListModel(parent) {
  init();
}

SessionLabelModel::~SessionLabelModel() {}

int SessionLabelModel::loadData(int page, int page_size) {
  QVector<SessionLabelData> newData =
      Storage::fetchDataFromDatabase(page, page_size);
  if (newData.size() == 0) {
    return 0;
  }
  auto& t = Window::MediaStackWidget::Instance();
  for (auto i = newData.begin(); i != newData.end(); ++i) {
    // 遍历每一个  session 
    // 根据 session 获取 id
    // 在 history_data 表中查找 uid 的数据
    auto a = Storage::readHistoryData(i->id_);
    qDebug() << "Get: " << a.size();

    std::shared_ptr<Data::DocumentData> test =
        std::make_shared<Data::DocumentData>();
    // 设置 朋友唯一标识 id
    test->setUid(i->id_);
    // 设置标题名
    test->setName("idaaa");
    for (auto& t : a) {
      std::shared_ptr<Data::TextTalkData> o1 =
          std::make_shared<Data::TextTalkData>(t.msg_id_, t.message_,
                                               t.sender_id_, t.receiver_id_);
      test->appendChagMsg(o1);
    }

    auto win = new Window::MediaPreviewWidget(nullptr);
    win->setInfo(test);
    //t.addWidget(i->id_, new Window::MediaPreviewWidget(nullptr));
    t.addWidget(i->id_, win);
  }
  //for (au)
  // 根据 session_label 表的 id_ 查找 history_data 表 uid 的数据
  // 在这里执行插入数据到 Media 中？ 开辟一个线程？
  //Data::HistoryData tmp(o1->getMsgId(), 0, o1->getFromUid(), o1->getToUid(),
  //              o1->getMsgContent(), QString("TEST"));
  //Storage::InsertHistoryData();
  
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
  if (role == tRole) {
    // 输出了 2 次
    //qDebug() << index.row();
    return QVariant::fromValue(data_[index.row()]);
  } else {
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
    this->setData(this->index(i), QVariant::fromValue(data_.at(i)), tRole);
    //qDebug() << (Storage::tSessionLabelData).at(i).session_label_icon_path;
  }
}

}  // namespace Data

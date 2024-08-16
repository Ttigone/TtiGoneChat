/*****************************************************************//**
 * \file   data_session_label.h
 * \brief  朋友列表的模型
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef DATA_SESSION_LABEL_H
#define DATA_SESSION_LABEL_H

#include <QAbstractListModel>


#define tRole 0xf3f3


namespace Data {

class SessionLabelModel : public QAbstractListModel {
  Q_OBJECT
 public:
  explicit SessionLabelModel(QObject *parent = nullptr);
  ~SessionLabelModel();

 protected:
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role) const override;

 public:
  void updateModel(const QModelIndex &index, const QDateTime &time);

 signals:

 private:
  void init();

  //std::map<int64_t, CellData> m_userMap;
  int64 all_record_;        // 所有的记录
};

} // namespace Data



#endif  // !DATA_SESSION_LABEL_H

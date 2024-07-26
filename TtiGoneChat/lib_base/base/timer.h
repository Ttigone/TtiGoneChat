#ifndef TIMER_H
#define TIMER_H
#include "basic_types.h"

QT_BEGIN_NAMESPACE
class QObject;
class QThread;
QT_END_NAMESPACE

namespace base {
class Timer final : QObject {
 public:
  explicit Timer(std::unique_ptr<QThread*> thread,
                 std::function<void()> callback = nullptr);
  explicit Timer(std::function<void()> callback = nullptr);

  static Qt::TimerType DefaultType(int64 timeout) {
    constexpr auto t = int64(240);
    return (timeout < t) ? Qt::PreciseTimer : Qt::CoarseTimer;
  }

  /// @brief 设置回调函数
  void setCallBack(std::function<void()> callback) { callback_ = callback; }

  void callOnce(int64 timeout) { callOnce(timeout, DefaultType(timeout)); }

  void callOnce(int64 timeout, Qt::TimerType type) {
    start(timeout, type, Repeat::SingleTrigger);
  }

  /// @brief 定时器是否已经启动
  [[nodiscard]] bool isActive() const { return timer_id_ != 0; }

  /// @brief 取消
  void cancle();

 protected:
  void timerEvent(QTimerEvent* event) override;

 private:
  /// @brief 触发规则
  /// @details Interval: 每隔一段时间触发一次 SingleTrigger: 只触发一次
  enum class Repeat : unsigned {
    Interval = 0,
    SingleTrigger = 1,
  };

  void start(int64 timeout, Qt::TimerType type, Repeat repeat);
  void adjust();

  void setTimerout(int64 timeout);
  int timeout() const;

	void setRepeat(Repeat repeat)
	{
		repeat_ =  static_cast<unsigned>(repeat);
	}
  Repeat repeat() const
	{
		return static_cast<Repeat>(repeat_);
	}

  std::function<void()> callback_;
  int64 next_ = 0;
  int timeout_ = 0;
  int timer_id_ = 0;

  Qt::TimerType type_ : 2;  // 2 位 bit

#if __cplusplus >= 202002L
  bool adjusted_ : 1 = false;
  unsigned repeat_ : 1 = 0;

#else __cplusplus >= 201703L
	bool adjusted_ : 1;
	unsigned repeat_ : 1;
#endif


};

}  // namespace base

#endif  // TIMER_H

/*****************************************************************/ /**
 * \file   singleton.h
 * \brief  单例模板模式
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef BASE_SINGLETON_H
#define BASE_SINGLETON_H

#include <memory>
#include <mutex>

namespace base {

//template <class T>
//class Singleton {
// public:
//  template <typename... Args>
//  static T* Instance(Args&&... args) {
//    std::call_once(
//        flag_, [&]() { instance_.reset(new T(std::forward<Args>(args)...)); });
//    return instance_.get();
//  }
//
//  static void destroy() {
//    std::call_once(destroy_flag, [&]() { instance_.reset(nullptr); });
//  }
//
// protected:
//  Singleton() = default;
//  ~Singleton() = default;
//  Singleton(const Singleton&) = delete;
//  Singleton& operator=(const Singleton&) = delete;
//
// private:
//  static std::unique_ptr<T> instance_;
//  static std::once_flag flag_;
//  static std::once_flag destroy_flag;
//};
//
//template <class T>
//std::unique_ptr<T> Singleton<T>::instance_ = nullptr;
//
//template <class T>
//std::once_flag Singleton<T>::flag_;
//
//template <class T>
//std::once_flag Singleton<T>::destroy_flag;

template <typename T>
class Singleton {
 protected:
  Singleton() = default;
  Singleton(const Singleton<T>&) = delete;
  Singleton& operator=(const Singleton<T>&) = delete;

  static std::shared_ptr<T> instance_;

 public:
   template <typename ... Args>
  static std::shared_ptr<T> Instance(Args&& ...args) {
    static std::once_flag flag;
    std::call_once(flag, [&]() { instance_ = std::shared_ptr<T>(new T(std::forward<Args>(args)...)); });

    return instance_;
  }
  void PrintAddress() { qDebug() << instance_.get(); }
  ~Singleton() { qDebug() << "this is singleton destruct"; }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::instance_ = nullptr;


}  // namespace base

#endif  // BASE_SINGLETON_H

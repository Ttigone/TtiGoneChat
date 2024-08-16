/*****************************************************************//**
 * \file   singleton.h
 * \brief  单例模板模式
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef BASE_SINGLETON_H
#define BASE_SINGLETON_H

namespace base {

template <class T>
class Singleton {
 public:
  template <typename... Args>
  static T* Instance(Args&&... args) {
    std::call_once(flag_,
                   [&]() { instance_ = new T(std::forward<Args>(args)...); });
    return instance_;
  }

  static void destroy() {
    if (instance_) {
      delete instance_;
      instance_ = NULL;
    }
  }

 private:
  Singleton() = default;
  ~Singleton() = default;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;


  static T* instance_;
  static std::once_flag flag_;
};

template <class T>
T* Singleton<T>::instance_ = NULL;

template <class T>
std::once_flag Singleton<T>::flag_;

} // namespace base

#endif  // BASE_SINGLETON_H

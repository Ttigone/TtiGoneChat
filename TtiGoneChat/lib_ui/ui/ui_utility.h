/*****************************************************************//**
 * \file   ui_utility.h
 * \brief  
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef UI_UTILITY_H
#define UI_UTILITY_H


namespace Ui {

template <typename Value, typename Parent, typename... Args>
inline Value *CreateChild(Parent parent, Args &&...args) {
  //if constexpr (std::is_pointer_v<Parent>) {
  //  Expects(parent != nullptr);
  //  if constexpr (std::is_base_of_v<QObject, Value>) {
  //    return new Value(parent, std::forward<Args>(args)...);
  //  } else {
  //    // return CreateChild<
  //  }

  //} else if constexpr () {
  //}
}

}  // namespace Ui

#endif  // UI_UTILITY_H

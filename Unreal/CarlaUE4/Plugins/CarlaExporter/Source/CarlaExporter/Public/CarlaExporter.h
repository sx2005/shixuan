// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <string>

//用于构建工具栏和菜单。
class FToolBarBuilder;
class FMenuBuilder;

//定义一个枚举类型AreaType，用于表示不同的区域类型。
enum AreaType
{
  ROAD,
  GRASS,
  SIDEWALK,
  CROSSWALK,
  BLOCK
};

//定义一个类FCarlaExporterModule，它继承自IModuleInterface，用于实现模块的接口。
class FCarlaExporterModule : public IModuleInterface
{
public:

  /// IModuleInterface 实现
  //重写IModuleInterface中的StartupModule和ShutdownModule函数，用于模块的启动和关闭。
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;

  //定义一个函数PluginButtonClicked，这个函数将被绑定到一个命令，通常用于插件按钮的点击事件。
  //这个函数将被绑定到命令
  void PluginButtonClicked();

private://声明私有成员和函数，仅在类内部可见。

  //定义一个私有函数AddMenuExtension，用于向菜单添加扩展。
  void AddMenuExtension(FMenuBuilder& Builder);
  //定义一个私有函数WriteObjectGeom，用于写入对象的几何信息到文件。
  int32 WriteObjectGeom(std::ofstream &f, FString ObjectName, UBodySetup *body, FTransform &CompTransform, AreaType Area, int32 Offset);

//声明一个私有成员PluginCommands，用于存储插件的UI命令列表。
private:
  TSharedPtr<class FUICommandList> PluginCommands;
};

kicex
==

西电高清vod客户端

使用说明
./kicex init 		//获取所有电影信息
./kicex inquiry 电影名称	//获取查询电影（支持模糊查询）
./kicex open 电影名称	//获取电影信息
./kicex play 		//打开电影（仍旧不完善）

请使用ubantu的朋友将 kicex里的#!/bin/sh 改为#!/bin/bash 将== 改为 = ；并xargs mplayer 改为 xargs 你的播放器名称 （vlc totem等）
				->edit by axlecho

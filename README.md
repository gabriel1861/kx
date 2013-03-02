kicex
==

西电高清vod客户端

使用说明
./kicex init        (不用参数）
./kicex inquiry 海贼王 （支持模糊查询 类似yum list）
./kicex open 影片名称 （空格 括号在前面加 \ 不然shell不认）
./kicex play
./kicex play2

请使用ubantu的朋友将 kicex里的#!/bin/sh 改为#!/bin/bash 将== 改为 = ；并xargs mplayer 改为 xargs 你的播放器名称 （vlc totem等）
				->edit by axlecho

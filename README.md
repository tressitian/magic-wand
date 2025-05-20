# TECHIN515 Magic Wand

## 项目简介
本项目为 TECHIN515 课程的 Magic Wand 手势识别系统，包括数据采集、模型训练、硬件设计等内容。

## 目录结构
```
TECHIN515-magic-wand/
├── src/
│   ├── sketches/               # Edge Impulse 导出和注释草图
│   ├── python-scripts/         # 数据采集与处理脚本
│   └── dataset/                # 采集的数据集
├── docs/                      # 文档材料
├── media/                     # 演示视频等
├── enclosure/                 # 外壳设计文件与说明
│   ├── final-enclosure-images/
│   └── notes.md
├── README.md                  # 项目说明
└── .gitignore                 # 忽略文件配置
```

## 安装依赖
建议使用 Python 3.7 及以上版本。

```bash
pip install pyserial
```

## 数据采集脚本运行方法

1. 确保 ESP32 已连接电脑。
2. 运行脚本（自动检测串口）：
   ```bash
   python src/python-scripts/gesture_capture/process_gesture_data.py
   ```
3. 如需指定串口、手势名、采集者名等参数：
   ```bash
   python src/python-scripts/gesture_capture/process_gesture_data.py --port /dev/cu.SLAB_USBtoUART --gesture wave --person alice
   ```
4. 列出可用串口：
   ```bash
   python src/python-scripts/gesture_capture/process_gesture_data.py --list-ports
   ```

## 其他说明
- 采集的数据会自动保存在 `data/gesture/` 目录下。
- 外壳设计、材料说明等请见 `enclosure/notes.md`。
- 详细报告与演示视频请见 `docs/` 和 `media/` 目录。 
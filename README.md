# TECHIN515 Magic Wand

## Project Introduction
This project is for the TECHIN515 course and implements a Magic Wand gesture recognition system, including data collection, model training, and hardware design.

## Directory Structure
```
TECHIN515-magic-wand/
├── src/
│   ├── sketches/               # Edge Impulse exports and sketches with comments
│   ├── python-scripts/         # Python scripts for data collection and processing
│   └── dataset/                # Collected datasets
├── docs/                      # Documentation materials
├── media/                     # Demo videos, etc.
├── enclosure/                 # Enclosure design files and notes
│   ├── final-enclosure-images/
│   └── notes.md
├── README.md                  # Project instructions
└── .gitignore                 # Ignore file configuration
```

## Install Dependencies
Python 3.7 or above is recommended.

```bash
pip install pyserial
```

## How to Run the Data Collection Script

1. Make sure your ESP32 is connected to your computer.
2. Run the script (auto-detect serial port):
   ```bash
   python src/python-scripts/gesture_capture/process_gesture_data.py
   ```
3. To specify serial port, gesture name, and person name:
   ```bash
   python src/python-scripts/gesture_capture/process_gesture_data.py --port /dev/cu.SLAB_USBtoUART --gesture wave --person alice
   ```
4. To list available serial ports:
   ```bash
   python src/python-scripts/gesture_capture/process_gesture_data.py --list-ports
   ```

## Additional Notes
- Collected data will be automatically saved in the `data/gesture/` directory.
- For enclosure design and material notes, see `enclosure/notes.md`.
- For detailed reports and demo videos, see the `docs/` and `media/` directories. 
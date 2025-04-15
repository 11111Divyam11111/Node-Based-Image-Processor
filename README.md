 Node-Based Image Processing Editor

An interactive, visual image processing tool built with Qt and C++, using a node-based architecture where each operation is represented as a visual node connected through input/output ports.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 🚀 Features

- 🎛️ Node-Based Interface — Drag-and-drop nodes and connect them visually
- 🖼️ Image Input/Output — Load and display images through nodes
- 🌈 Grayscale Conversion — Convert any image to grayscale
- 📈 Brightness/Contrast Control (planned) — Adjust brightness and contrast
- 🔌 Interactive Connection Wiring — Connect ports via dynamic wires
- 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 🧠 Architecture Overview

 🧱 Core Components

| Component         | Description |
|------------------|-------------|
| `BaseNode`        | Abstract base class for all nodes (title, layout, ports) |
| `Port`            | Input/output port for data transfer |
| `Connection`      | Visual wire connecting output ports to input ports |
| `NodeCanvas`      | Custom `QGraphicsScene` to manage node layout and connections |
| `DragManager`     | Singleton handling interactive wire dragging between ports |

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 🎮 User Flow

1. User clicks an Output Port  
   → A temporary wire follows the mouse cursor.

2. User drags to an Input Port  
   → If valid, a `Connection` is created between the ports.

3. User releases the mouse elsewhere  
   → Temporary wire is discarded with no connection.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 📦 Implemented Nodes

| Node                | Description |
|---------------------|-------------|
| `ImageInputNode`    | Loads an image from disk |
| `GrayscaleNode`     | Converts image to grayscale |
| `ImageViewerNode`   | Displays the input image |
| `BrightnessContrastNode` | (Planned) Adjusts brightness and contrast |
| `ImageOutputNode`   | (Planned) Saves or displays final output |

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


 🧪 How to Run

 Prerequisites
- Qt 6.x or 5.x (with Qt Creator)
- C++17 compiler

 Build Instructions
```bash
git clone https://github.com/11111Divyam11111/NodeImageEditor.git
cd NodeImageEditor
Open in Qt Creator or run qmake manually

# Stock Predictor (C Language Course Project)

这是一个基于 **C语言** 实现的股票行情预测系统，最初开发环境为 Borland C 3.0，现在已整理上传到 GitHub 作为课程设计作品。

## 📌 功能特点
- **AR(p) 时间序列模型**：自动使用 AIC 准则选择最佳阶数  
- **技术指标分析**：支持 EMA、MACD、KDJ、WR 等  
- **遗传算法权重优化**：组合多指标，提高预测准确率  
- **数据输入输出**：从 CSV 文件读取历史行情数据，输出预测结果  

## 📂 目录结构
```
stock-predictor-modern-lite/
├── final/
│   └── cks/            # 源代码目录（main.c 等所有 .c/.h 文件）
│
├── data/               # 数据文件
│   └── sample_data.csv
│
├── doc/                # 文档材料
│   └── 14-白宇轩-郝家辉.pptx
│
└── README.md           # 项目说明文件
```

## 🚀 编译与运行

### macOS / Linux
```bash
cd stock-predictor-modern-lite
gcc -std=c99 -O2 -Wall -o spredict final/cks/*.c -lm
./spredict data/sample_data.csv
```

### Windows (MinGW)
```bash
cd stock-predictor-modern-lite
gcc -std=c99 -O2 -Wall -o spredict.exe final/cks/*.c -lm
spredict.exe data/sample_data.csv
```

## 📊 示例输出
```
AR(p) with AIC p=4
Coeffs: 0.76908 0.11223 -0.04138 0.13324
Next 3 forecast: 110.337, 110.144, 110.037
GA weights: [ema=0.752, macd=0.315, kdj=-1.480, wr=2.082], bias=0.628
Validation accuracy: 0.674, confidence score: 0.344
```

## 🏷️ 注意事项
- 初版基于 Borland C (C89)，但已在现代编译器（gcc/clang）下可运行。  
- 数据文件需为 CSV 格式，包含日期、开盘价、收盘价、最高价、最低价、成交量。  
- 如果使用 Borland C，需在 DOS 环境下运行（不推荐）。  

## 👨‍💻 作者
- 郝家辉、白宇轩  
华中科技大学 · 人工智能与自动化学院

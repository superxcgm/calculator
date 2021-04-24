# 计算器

## 安装依赖
```shell
mkdir build
cd build
conan install ..
```

## 构建
```shell
cd build
cmake .. && cmake --build .
```

## 运行测试
```shell
cd build
./calculator_test
```
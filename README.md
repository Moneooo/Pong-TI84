# Pong-TI84
 A full pong game for the TI-84 Calculator

## Prerequisites
 - [**_TI Connect CE_**](https://education.ti.com/en/products/computer-software/ti-connect-ce-sw) 
    > For transferring the program file to your calculator
 - [**_arTIfiCE_**](https://yvantt.github.io/arTIfiCE/) 
    > For running the program on newer versions of the calculator os.
 - [**_Cesium_** _(optional but recommended)_](https://github.com/mateoconlechuga/cesium)
    > Helps with easy navigation of programs on the calculator
 - [**_CEmu_** (_optional_)](https://github.com/CE-Programming/CEmu?tab=readme-ov-file) 
    > For emulating the calculator to run the program on pc

## How to Install

### From `.8xp` File (Recommended)
 1. Go to the **Releases** tab.
 2. Download the latest release.
 3. Copy the `Pong.8xp` file to your calculator using **TI Connect CE**.

    You should now be able to run the game through **_arTIfiCE_** or **_Cesium_**

### Build from Source (Not recommended, requires some technical skill)
1. Download the source code.
2. Install the [**CE Toolchain**](https://ce-programming.github.io/toolchain/static/getting-started.html).
3. Run `make` in the `Pong-TI84` directory.
4. Copy `Pong.8xp` from the `bin/` folder to your calculator (using **TI Connect CE**) or **CEmu**.

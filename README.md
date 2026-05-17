# Ed's Keymaps

Keymaps for the keyboards I use (or plan to use in the near future).

## Custom QMK Fork

My keymaps are incompatible with the main QMK firmware branch, and must be compiled with [my custom QMK fork](https://github.com/edwardkopp/qmk_firmware).

## Flashing From Linux

I only flash my keyboards from Linux, so I only have Linux instructions. Install and set up QMK CLI using the following commands:

```shell
curl -fsSL https://install.qmk.fm | sh

# After installation
qmk setup
qmk doctor
```

### ZSA Voyager

To allow flashing, create `/etc/udev/rules.d/50-zsa.rules` with the following contents:

```shell
# ZSA Voyager flashing only
SUBSYSTEMS=="usb", ATTRS{idVendor}=="3297", MODE:="0666", SYMLINK+="ignition_dfu"
```

Then update udev rules:

```shell
udevadm control --reload-rules
udevadm trigger
```

To flash, you need to use [Zapp](https://github.com/zsa/zapp) instead of QMK. It's most convenient to just have the Zapp binary and the firmware binary in the same directory so flashes are just like this:

```shell
./zapp flash firmware.bin
```

## Mac Compatibility

I don't have dedicated layers for Mac as I just swap Command and Control in System Settings.

<img width="440" alt="Screenshot 2024-12-17 at 18 30 56" src="https://github.com/user-attachments/assets/f58469ba-8b38-4704-a6df-9a58a2bcaa14" />

## Original README

The original README can be found [here](https://github.com/qmk/qmk_userspace).

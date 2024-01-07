# Berlin Clock

## platformio commands

Init Project:
```shell
platformio init --board d1_mini
```

Compile:
```shell
platformio run
```

Upload to ESP:
Compile:
```shell
platformio run --target upload
```

Run tests:
Compile:
```shell
platformio test -e native
```
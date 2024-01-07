# Berlin Clock

## platformio commands

Init Project:
```shell
platformio init --board d1_mini
```

Compile:
```shell
platformio -e d1_mini run
```

Upload to ESP:
Compile:
```shell
platformio run -e d1_mini --target upload
```

Run tests:
Compile:
```shell
platformio test -e native
```
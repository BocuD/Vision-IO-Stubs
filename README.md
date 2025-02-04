# Vision-IO-Stubs

These are some stub DLLs i created a few months ago with the goal of writing full network support. I have basic network support working and might release that as well at some point, but for now i'm making this public for anyone who might be interested.

Stub DLLs to allow tetote connect data to run

aeroTAP_CAM: seems to be what talks to the camera driver normally. Only has dummy responses.
DeviceCheck: Literally only gets used to check if a touchscreen is present, which is bypassed.
VisionUSBIO: JVS IO communication.

Input is mapped to keyboard:
- coin: c
- test: t
- service: s
- select: space
- enter: return
- insert nesica card: p (ID is hardcoded to 7020392002630000)

Amusement IC cards aren't implemented

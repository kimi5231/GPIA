pushd %~dp0

protoc.exe -I=./ --cpp_out=./ ./Enum.proto
protoc.exe -I=./ --cpp_out=./ ./Struct.proto
protoc.exe -I=./ --cpp_out=./ ./Protocol.proto

IF ERRORLEVEL 1 PAUSE

XCOPY /Y Enum.pb.h "../../../Server"
XCOPY /Y Enum.pb.cc "../../../Server"
XCOPY /Y Struct.pb.h "../../../Server"
XCOPY /Y Struct.pb.cc "../../../Server"
XCOPY /Y Protocol.pb.h "../../../Server"
XCOPY /Y Protocol.pb.cc "../../../Server"

XCOPY /Y Enum.pb.h "../../../DummyClient"
XCOPY /Y Enum.pb.cc "../../../DummyClient"
XCOPY /Y Struct.pb.h "../../../DummyClient"
XCOPY /Y Struct.pb.cc "../../../DummyClient"
XCOPY /Y Protocol.pb.h "../../../DummyClient"
XCOPY /Y Protocol.pb.cc "../../../DummyClient"

XCOPY /Y Enum.pb.h "../../../Zelda"
XCOPY /Y Enum.pb.cc "../../../Zelda"
XCOPY /Y Struct.pb.h "../../../Zelda"
XCOPY /Y Struct.pb.cc "../../../Zelda"
XCOPY /Y Protocol.pb.h "../../../Zelda"
XCOPY /Y Protocol.pb.cc "../../../Zelda"

DEL /Q /F *.pb.h
DEL /Q /F *.pb.cc
DEL /Q /F *.h

PAUSE
import sys
import os

def get_occt_include_directory():
	if os.path.exists("./servoce-third-libs-travis/linux-include-7.4"):
		return "./servoce-third-libs-travis/linux-include-7.4"

	if os.path.exists("./servoce-third-libs-travis/osx-include"):
		return "./servoce-third-libs-travis/osx-include"

	dirs = ["/usr/include/", "/usr/local/include/"]
	subdirs = ["occt", "opencascade"]

	for d in dirs:
		if os.path.exists(d):
			for f in subdirs:
				fp = os.path.join(d, f)
				if os.path.exists(fp):
					return fp 

	raise Exception("can't find occt")

print("export OCCT_INCLUDE={}".format(get_occt_include_directory()))
#print("OCCT_LIB={}", format=get_occt_include_directory())
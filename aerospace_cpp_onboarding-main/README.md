# Aerospace_Cpp_Onboarding
Onboarding material for https://nearth.atlassian.net/wiki/spaces/nearthlab/pages/2914189618/C+4

# Prerequisites
Install lib-nlab-math (https://github.com/nearthlab/lib-nlab-math)
Follow readme in the repo

# Installation
To install, use following commands in each folders (ex: m300, m600, mavic, skydio)
``` bash
cmake .
make
sudo make install
```

To uninstall,
``` bash
sudo xargs rm < install_manifest.txt
```

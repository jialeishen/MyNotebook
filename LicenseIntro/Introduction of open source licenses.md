# Introduction of open source licenses
## Open source license
About open source licenses (from [opensource.org](https://opensource.org/licenses))
>Open source licenses are licenses that comply with the Open Source Definition — in brief, they allow software to be freely used, modified, and shared. To be approved by the Open Source Initiative (also known as the OSI), a license must go through the Open Source Initiative's license review process.
## Popular open source licenses
According to the survey by [Synopsys](https://www.synopsys.com/blogs/software-security/top-open-source-licenses/), the most popular open source licenses used by developers and their restriction are listed below.

|Rank|License|Usage|Restriction|
|:---:|---|---|---|
|1|MIT License|32%|*|
|2|GNU GPL 2.0|18%|***|
|3|Apache License 2.0|14%|*|
|4|GNU GPL 3.0|7%|***|
|5|BSD License 2.0|6%|*|
|6|ISC License|5%|*|
|7|Artistic License (Perl)|4%|**|
|8|GNU LGPL 2.1|4%|***|
|9|GNU LGPL 3.0|2%|***|
|10+|Other licenses|<1%||

## Introduction of open source licenses
Detailed introduction of different open source licenses can be found on [choosealicense.com](https://choosealicense.com/licenses/). 
## Comparison between licenses
The original comparison between more licenses can be found on [choosealicense.com](https://choosealicense.com/appendix/). The comparison between some popular licenses is shown below.

|License|Commercial use|Distribution|Modification|Patent use|Private use|Disclose source|License and copyright notice|Network use is distribution|Same license|State changes|Liability|Trademark use|Warranty|
|---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|GNU GPL 2.0|:green_circle:|:green_circle:|:green_circle:||:green_circle:|:blue_circle:|:blue_circle:||:blue_circle:|:blue_circle:|:red_circle:||:red_circle:|
|GNU GPL 3.0|:green_circle:|:green_circle:|:green_circle:|:green_circle:|:green_circle:|:blue_circle:|:blue_circle:||:blue_circle:|:blue_circle:|:red_circle:||:red_circle:|
|MIT License|:green_circle:|:green_circle:|:green_circle:||:green_circle:||:blue_circle:||||:red_circle:||:red_circle:|
|Apache License 2.0|:green_circle:|:green_circle:|:green_circle:|:green_circle:|:green_circle:||:blue_circle:|||:blue_circle:|:red_circle:|:red_circle:|:red_circle:|

## How to choose a open source license?
[choosealicense.com](https://choosealicense.com/) webpage provides a simple guidance for selecting an open source license for your code.
Paul Pagwell also draw a flowchart for guiding developers to select the open source license.
![open source license selection flowchart](resource\open-source-licences.png)
## Examples of license used by building performance analysis tools
### [EnergyPlus](https://github.com/NREL/EnergyPlus)
 * License: Own licensing condition (similar to GNU GPL 3.0, plus some authorization terms)
 * Dependencies:
### [OpenStudio](https://github.com/NREL/OpenStudio)
 * License: Own licensing condition (similar to GNU GPL 3.0, plus some authorization terms)
 * Dependencies: EnergyPlus
### [Ladybug for Grasshopper](https://github.com/ladybug-tools/ladybug-legacy)
 * License: GNU GPL 3.0
 * Dependencies: Rhinoceros RhinoCommon; Radiance; CBE Comfort Tool; other packages and tools
### [Honeybee for Grasshopper](https://github.com/ladybug-tools/honeybee-legacy)
 * License: GNU GPL 3.0
 * Dependencies: Rhinoceros RhinoCommon; Radiance; Ladybug; other packages and tools
### [Radiance](https://github.com/NREL/Radiance)
 * License: Own licensing condition (similar to GNU GPL 3.0, plus some authorization terms)
 * Dependencies:
### [CBE Comfor Tool](https://github.com/CenterForTheBuiltEnvironment/comfort_tool)
 * License: GNU GPL 2.0
 * Dependencies: 
### [Rhinoceros RhinoCommon](https://github.com/mcneel/rhinocommon) 
 * License: GNU GPL 3.0
 * Dependencies: 
### [OpenFOAM](https://openfoam.org/licence/) 
 * License: GNU GPL 3.0
 * Dependencies: 
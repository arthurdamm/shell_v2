# simple shellv2

![shellv2-screenshot](https://github.com/arthurdamm/shell_v2/blob/master/img/shellv2_screenshot.png)

### Overview
`simple shell` is a UNIX command interpreter that replicates core functionalities of the `sh` shell. This project was developed as part of the third month curriculum at [Holberton School](https://www.\holbertonschool.com/), San Francisco.

### Installation
Clone this repository to your local system and compile using `gcc -Wall -Werror -Wextra -pedantic *.c`.

### Usage
* Once in the shell, use exactly like `sh`. A list of covered features is provided below. The shell can run in either interactive or non-interactive mode.
* Function returns with the specified exit status.

### Features
The shell handles command line input, including arguements, without the use of most standard library functions such as `printf`, `strtok`, or `getline`. In addition to running executables in the PATH, the following features are currently implemented.

|  Builtin Commands  |    Functionality                            |
| ------------------ | ------------------------------------------- |
| `exit [status]`    | Exit shell with specified exit status       |
| `env`              | Print list of current environment variables |
| `setenv`           | Set an environment variable                 |
| `unsetenv`         | Unset an environment variable               |
| `cd`               | Change directories                          |
| `history`			 | Prints command history					   |
| `help` 			 | Displays help for builtin commands		   |
| `alias`			 | Alias a command as another or print aliases |

|  Other Features    |    Functionality                            |
| ------------------ | ------------------------------------------- |
| `Ctrl-D`           | End of file - exit shell                    |
| `Ctrl-C`           | Does not exit shell - (Differs from `sh`)   |
| `;`                | Command separator, allows command chaining  |
| `#`                | Comment indicator                           |
| `<`				 | Redirect input							   |
| `>`				 | Redirect output							   |
| `<<`				 | Append input (heredoc)					   |
| `>>`				 | Append output							   |

### Example Usage
* This shell takes input the same as a standard unix shell.  After running the executable `hsh`, enter desired input and press return.
* `ls -l`
* `exit 98`
* `cd -`

### Release History
* 0.0.1 - First release - 17 Apr 2019
* 0.0.2 - Second release - 03 Mar 2020

### About
All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4` with the following flags: `-Wall -Werror -Wextra -pedantic`

### Authors
* Jason Cortella [Github](https://github.com/jasoncortella) - [Twitter](https://twitter.com/JasonCortella)
* [Arthur Damm](https://github.com/arthurdamm/twodoor) ~ [LinkedIn](https://www.linkedin.com/in/arthur-damm-96527042/) ~ [@arthurdamm](https://twitter.com/arthurdamm):
*Sharpening my skills at Holberton School of Software Engineering. I have a lifelong passion for programming with a background in mathematics and a daily meditation practice. Spent the last several years enjoying working as a private tutor and am now excited to practice software wizardry professionally.*
* Thomas Graeff [Github](https://github.com/graefft)

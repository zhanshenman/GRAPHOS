/**
*-------------------------------------------------
*  Copyright 2016 by Tidop Research Group <daguilera@usal.se>
*
* This file is part of GRAPHOS - inteGRAted PHOtogrammetric Suite.
*
* GRAPHOS - inteGRAted PHOtogrammetric Suite is free software: you can redistribute
* it and/or modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation, either
* version 3 of the License, or (at your option) any later version.
*
* GRAPHOS - inteGRAted PHOtogrammetric Suite is distributed in the hope that it will
* be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*
* @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>
*-------------------------------------------------
*/
#include "libPW.h"
#include "ConvertProcess.h"

using namespace PW;

ConvertProcess::ConvertProcess(QString inputPath, QString outputPath):
    ExternalProcess(TOOLS_CONVERT_COMMAND)
{
    QString workingDir = mCommandPath.left(mCommandPath.lastIndexOf(QRegExp("/")));
    workingDir = workingDir.left(workingDir.lastIndexOf(QRegExp("/"))+1);
    setWorkingDir(workingDir);

    setStartupMessage("Converting images to png...");
    setStdOutputFilePath(LibPW::getStdErrorPath() + "/convert.log");
    setStdErrorFilePath(LibPW::getStdErrorPath() + "/convertError.log");

    addIntputs(QStringList() << inputPath << outputPath);
}


from src.Data_Ingestor import Preprocessor
import sys

def parseOptions():
    optionMap = {}
    optionMap["lvf"], optionMap["hcf"], optionMap["rf"] = False
    Options = sys.argv
    Options = Options[:-1]
    for i in range(0, len(Options) - 1):
        if Options[i] == "lvf":
            optionMap["lvf"] = True
        elif Options[i] == "hcf":
            optionMap["hcf"] = True
        elif Options[i] == "-f":
            i = i + 1
            optionMap["filePath"] = Options[i]
        elif Options[i] == "-nf":
            i = i + 1
            optionMap["n_features"] = Options[i]
        elif Options[i] == "-nl":
            i = i + 1
            optionMap["n_labels"] = Options[i]
        elif Options[i] == "-rf":
            optionMap["rf"] = True
        elif Options[i] == "-ttsplit":
            i = i + 1
            optionMap["ttsplit"] = Options[i]
    return optionMap


def readAndIngest(Options):
    Preprocessor.preProcessData(Options["filePath"], Options["n_features"], Options["n_labels"], Options["lvf"],
                                Options["hcf"], Options["rf"], Options["ttsplit"])


if name == "__main__":
    # data_proecessing_pipeline
    Options = parseOptions()
    readAndIngest(Options)
    #runAnalyzer()

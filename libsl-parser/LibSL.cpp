#include "LibSL.h"
#include "LibSLParser.h"
#include "LibSLLexer.h"
#include "antlr4-runtime.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <utility>  // Для std::move

using namespace antlr4;

namespace {
    struct ParseContext {
        ANTLRInputStream input;
        LibSLLexer lexer;
        CommonTokenStream tokens;
        LibSLParser parser;
        std::unique_ptr<LibSLParser::FileContext> parseTree;

        ParseContext(const std::string& inputStr)
                : input(inputStr),
                  lexer(&input),
                  tokens(&lexer),
                  parser(&tokens) {
            tokens.fill();
        }
    };

    std::unique_ptr<ParseContext> currentContext;
}

bool LibSL::parseFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return parseFromString(buffer.str());
}

bool LibSL::parseFromString(const std::string& input) {
    try {
        currentContext = std::make_unique<ParseContext>(input);
        // Используем reset для присвоения нового значения unique_ptr
        currentContext->parseTree.reset(currentContext->parser.file());
        std::cout << "Parsed successfully from string!" << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
        currentContext.reset();
        return false;
    }
}


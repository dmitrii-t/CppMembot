#include "graphnode.h"

#include "graphedge.h"

GraphNode::GraphNode(int id) {
    _id = id;
}

GraphNode::~GraphNode() {
    //// STUDENT CODE
    ////

    // GraphNode instance does not manage the _chatBot instance
    // thus it shouldn't call delete on it
    // delete _chatBot;
    
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) {
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge) {
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
    // use either move sematics or inline std::unique_ptr<GraphEdge>(edge) to add a
    // unique_ptr to the list
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot&& chatBot) {
    _chatBot = std::move(chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode) {
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr;  // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index) {
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
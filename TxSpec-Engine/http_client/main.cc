#include <HttpClient.h>

// using namespace std;
// int main() {
//     HttpClient client;
//     HttpClient client1("localhost", "9999", "/subgraphs/name/");


//     char* basic = (char*)malloc(8192);

//     int size = snprintf(basic, 8192, 
//                         "{\"query\":\"{relations(where:{contractAddress:\\\"%s\\\"}){binding{content}}}\"}", "BANK");


//     std::string test("{  \"query\"  : \"{  \\n rules(where:{name:\\\"ERC20\\\"}){content \\n id \\n }}\"}");

//     std::string query1("{\"query\":\"{transfers(where:{contractaddress:\\\"BANK\\\"}){ id \\n }}\"}");
    
//     std::string fromhttp("{\"query\":\"{transfers(where:{contract_address:\\\"bank\\\",hash:\\\"0x4ee3706df334461f97b4c52892eada4cfe91cf9d4aac9733c94dff4f23f3b756\\\"}){receiver \\n sender \\n timestamp \\n value \\n }}\"}");
//     std::cout << query1 << std::endl;
//     char* encodeString = (char*)malloc(8192);

//     client.query(fromhttp.c_str(), "regchain-bank-subgraph");
//     client1.query(fromhttp.c_str(),"regchain-bank-subgraph");
// }
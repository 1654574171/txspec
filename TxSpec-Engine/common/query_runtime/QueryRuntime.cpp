#include "QueryRuntime.h"

using namespace request_proto;
using namespace std;

QueryRuntime::QueryRuntime()
{
    QueryEntityERC20Impl *erc20 = new QueryEntityERC20Impl();
    QueryEntityDABImpl *dab = new QueryEntityDABImpl();
    this->queryers[QueryType::ERC20] = erc20;
    this->queryers[QueryType::DAB] = dab;
}

string QueryRuntime::QueryEntityWithType(QueryType qType, TransactionInfo *tx)
{
    return this->queryers[qType]->QueryEntityString(tx);
}

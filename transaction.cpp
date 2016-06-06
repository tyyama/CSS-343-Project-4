//Factory Method
Transaction Transaction::*read_commands(string transType){
	if (transType == "B") return new Borrow;
	if (transType == "R") return new Return;
	if (transType == "I") return new Inventory;
	//case for "H": read customer's history. I'll write the following for now:
	if (transType == "H") return new History;
}
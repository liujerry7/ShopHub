## ShopHub
ShopHub is a console-based shopping mall simulation that models real online marketplaces.

Users authenticate into the system with login information like username/password and are routed into different experiences based on their role. Customers can browse stores, view merchandise with prices and quantities, and make purchases, while Merchants can create stores, manage inventory, and add new products.

The system persists all users, stores, and inventory using files, so state is preserved across sessions. Under the hood, it uses inheritance and polymorphism to separate customer and merchant behavior, and smart pointers to manage ownership safely.


# Webservers
## Wordpress Architecture Design 
### Tools
 - Front-end
   * WordPress Application (abstraction for setting HTML, CSS, and JS themes):
     * Theme Selection and Customization: WordPress allows users to choose from a vast library of pre-designed themes and customize them through a user-friendly interface. This abstracts away the need to write HTML, CSS, or JavaScript for basic styling and layout changes.
     * Content Creation and Management:  WordPress provides editors for creating pages and posts, allowing users to add text, images, and other media without directly interacting with HTML.
     * Plugin Integration: WordPress allows users to easily install plugins that extend functionality, often adding front-end features without requiring coding.
     * Underlying Languages:
       * HTML:  Defines the structure and content of web pages.
       * CSS: Controls the visual presentation and styling.
       * JS:  Adds interactivity and dynamic behavior to the front-end.
 - Back-end
   * WordPress (abstraction for user authentication, content logic organization, and database interaction):
     * User Management: WordPress handles user registration, login, and roles, abstracting away the complexities of user authentication and authorization.
     * Content Organization: WordPress provides a structured system for organizing content (pages, posts, categories, tags) and storing it in the database.
     * Database Interaction: WordPress handles all database interactions (retrieving, storing, and updating data) through its PHP code, shielding users from writing SQL queries.
     * Underlying Technologies:
       * PHP: The server-side language that powers WordPress, handling dynamic content generation, database interactions, and back-end logic.
       * Database (MySQL): Stores website content, settings, and user data.
   * Nginx Web Server:
     * Handles incoming requests from users.
     * Serves static content (HTML, CSS, JavaScript, images) efficiently.
     * Acts as a reverse proxy, passing dynamic requests to PHP-FPM for processing by WordPress.
- Key Takeaways
	- Abstraction Layers: WordPress provides crucial abstraction layers that simplify both front-end and back-end tasks, making web development more accessible to a wider audience.
	 * Modular Architecture: WordPress's use of themes and plugins promotes a modular approach, allowing users to easily customize and extend functionality without deep technical expertise.
	 * Efficient Infrastructure:  Nginx's role in serving static content and handling high traffic complements WordPress's dynamic capabilities, resulting in a robust and performant web server architecture.
	 * This refined representation accurately captures the essence of how WordPress, Nginx, PHP, and MySQL work together to create a powerful and user-friendly web development platform.
### Data flow
1. Static Content Flow
	 * User Request: The user's browser requests the webpage (HTML), stylesheet (CSS), and any JavaScript files needed for the page.
	 * Nginx's Role:
	   * Nginx receives the requests and checks if it has those static files in its cache. If so, it serves them directly from the cache.
	   * If not cached, Nginx retrieves the files from the filesystem (where WordPress stores its theme files).
	   * Nginx sends the static files (HTML, CSS, JavaScript) to the user's browser.
	 * Browser Rendering: The browser receives the static files and renders the basic structure and style of the webpage.
1. Dynamic Content Flow
	 * Initial Page Load:
	   * The HTML received by the browser likely contains PHP code (from the WordPress theme) that needs to be executed on the server to generate dynamic content.
	   * The browser sends a request to Nginx for this dynamic content (e.g., the blog post content, comments, author information).
	 * Nginx to PHP-FPM:
	   * Nginx recognizes the request as a PHP script and passes it to PHP-FPM (FastCGI Process Manager).
	 * PHP and WordPress:
	   * PHP-FPM executes the PHP code, which is part of the WordPress application.
	   * WordPress interacts with the MySQL database to:
	     * Fetch the blog post content, author details, and comments.
	     * Format the data according to the theme's instructions.
	   * WordPress generates the final HTML output containing the dynamic content.
	 * Back to Nginx:  PHP-FPM sends the generated HTML back to Nginx.
	 * Nginx to Browser: Nginx sends the dynamic HTML content to the user's browser.
	 * Browser Updates: The browser receives the dynamic content and updates the webpage accordingly, displaying the blog post, comments, and other elements.
1. Key Points
	- Caching: Nginx can cache static content to improve performance by reducing disk access and server load.
	- PHP-FPM: This process manager handles the execution of PHP scripts, making the process more efficient.
	- Database Interaction: WordPress abstracts away the complexities of database interaction, making it easier to work with dynamic data.
	- Separation: This architecture efficiently separates the handling of static and dynamic content, leveraging the strengths of Nginx and PHP.
	- This data flow demonstrates how a web server with Nginx and PHP can effectively deliver both static and dynamic content, providing a foundation for building complex web applications like WordPress websites.
	
	

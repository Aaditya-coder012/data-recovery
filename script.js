// Smooth scroll for navigation
document.querySelectorAll('.nav-link').forEach(link => {
    link.addEventListener('click', function(e) {
        e.preventDefault();
        const targetId = this.getAttribute('href');
        document.querySelector(targetId).scrollIntoView({ behavior: 'smooth' });
    });
});

// Handle form submission
document.getElementById('tool-suggestion-form').addEventListener('submit', function(e) {
    e.preventDefault();
    const toolName = document.getElementById('tool-name').value;
    const sourceLink = document.getElementById('source-link').value;
    const messageDiv = document.getElementById('submission-message');

    // Simple validation and feedback (no backend, just frontend demo)
    if (toolName && sourceLink) {
        messageDiv.textContent = `Thank you! "${toolName}" with link "${sourceLink}" has been submitted for review.`;
        messageDiv.style.color = '#28a745';
        this.reset(); // Clear form
    } else {
        messageDiv.textContent = 'Please fill out both fields.';
        messageDiv.style.color = '#dc3545';
    }
});
# Use the latest stable version of Debian
FROM debian:stable-slim

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Update the package list
RUN apt-get update

# Install useful utilities
# Note: Customize this list based on your needs. For example, you might need build tools, git, etc.
RUN apt-get install -y \
    curl \
    git \
    vim \
    build-essential \
    python3 \
    python3-pip \
    python3-dev \
    pipx \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*

 RUN pipx ensurepath

# Clean up to keep the image small
RUN apt-get clean && rm -rf /var/lib/apt/lists/*


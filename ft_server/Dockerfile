# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaubert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 10:33:53 by agaubert          #+#    #+#              #
#    Updated: 2020/02/28 19:48:05 by agaubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster AS debian
COPY srcs/ /
RUN ["/bin/bash", "-c", "/bootstrap.sh"]
EXPOSE 80 443
ENTRYPOINT ["/bin/bash", "-c", "/startup.sh"]
#ENTRYPOINT ["/usr/local/bin/supervisord", "-c", "/supervisor/supervisord.conf"]

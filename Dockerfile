FROM openfaas/classic-watchdog:0.18.0 as watchdog

FROM lucasfsduarte/alpine-build-base

# Allows you to add additional packages via build-arg
ARG ADDITIONAL_PACKAGE

COPY --from=watchdog /fwatchdog /usr/bin/fwatchdog
RUN chmod +x /usr/bin/fwatchdog

WORKDIR /app/

COPY function/header.h      .
COPY function/manager.c     .
COPY handler.c              .

RUN gcc header.h manager.c handler.c -static -o /handler \
    && chmod +x /handler

ENV fprocess="/handler"

HEALTHCHECK --interval=3s CMD [ -e /tmp/.lock ] || exit 1

CMD ["fwatchdog"]
